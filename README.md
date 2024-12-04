# Philosophers
<img src="assets/2.png" width="166" height="166"/>

<!-- ### skills -->
🍽 Language : C <br>
🍝 Build : Makefile (flags -Wall, -Wextra, -Werro, use cc)

<!-- No leaks <br>
No global variables <br>
No data race <br> -->
<!-- #### Introduction -->

둥근 테이블에 한명 이상의 철학자 그 수 만큼의 포크가 있습니다.
각 철학자는 독립적으로 실행되는 스레드로 먹거나, 생각하거나, 잠을 자는 등 한번에 하나의 행동을 수행합니다.
양쪽 포크를 사용하여 밥을 먹고, 식사 후엔 포크를 내려놓습니다. 포크는 뮤텍스를 사용하여 보호됩니다. 프로그램은 교착상태를 피하며 메모리 누수를 허용하지 않습니다. 수명 이상으로 굶는다면 철학자는 죽습니다. 


<!-- must not have any data races. no leaks  -->

<!-- 🍽 Language : C <br>
🍝 Build : Makefile -->


#### Following arguments: <br>

이 프로그램은 철학자의 수, 수명, 밥먹는 시간, 잠자는 시간, 총 식사 횟수(option)을 인자로 받습니다.

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```




◦number_of_philosophers: The number of philosophers and also the number
of forks. <br>
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.<br>
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks. <br>
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping. <br>
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.


#### External functs
```
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
```

<br>
• Each philosopher should be a thread.
• There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
• To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.


<br>

<!-- timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number. -->

