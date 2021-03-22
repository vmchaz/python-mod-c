#include "animal.h"

void animal_init(Animal * animal)
{
    memset(animal, 0, sizeof(Animal));
}

void animal_run_tick(Animal * animal, bool stop_on_action, bool one_thread_per_tick, int maxsteps)
{
    if (one_thread_per_tick)
    {
        int t = animal->next_thread;
        vcpu_run(&animal->vcpus[t], &animal->sequences[t], &animal->unitvarstruct, stop_on_action, maxsteps);
        animal->next_thread = (animal->next_thread + 1) % 16;
    }
    else
    {
        for(int i=0; i<16; i++)
            vcpu_run(&animal->vcpus[i], &animal->sequences[i], &animal->unitvarstruct, stop_on_action, maxsteps);
    }
}
