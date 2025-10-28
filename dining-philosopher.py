import threading
import time
import random 

forks = [threading.Semaphore(1) for _ in range(5)]

def philosopher(id):
    
        if id % 2 == 0:
            forks[id].acquire() #pick up 1st fork for case of 2
            forks[(id + 1) % 5].acquire() # pick up 2nd fork for case of 2
        else:
            forks[(id + 1) % 5].acquire() # pick up 1st fork for case of 1, which will send it to waiting  until 2 finishes
            forks[id].acquire() # pick up 2nd fork for case of 1
    
        print(f"🍽️ Philosopher {id} is eating.")
        forks[id].release()
        print(f"🍽️ Philosopher {id} is done eating and thinking again.")
        forks[(id + 1) % 5].release()

t1 = threading.Thread(target=philosopher, args=(0,))
t2 = threading.Thread(target=philosopher, args=(1,))
t3 = threading.Thread(target=philosopher, args=(2,))
t4 = threading.Thread(target=philosopher, args=(3,))
t5 = threading.Thread(target=philosopher, args=(4,))

t1.start()
t2.start()
t3.start()
t4.start()
t5.start()
t1.join()
t2.join()
t3.join()
t4.join()
t5.join()
