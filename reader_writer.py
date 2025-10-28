import threading
import time
import random

# Semaphores
mutex = threading.Semaphore(1)   # Protects read_count
rw_mutex = threading.Semaphore(1) # Allows either multiple readers OR one writer

read_count = 0   # Number of active readers

def reader(id):
    global read_count
    
    time.sleep(random.random())  # Simulate arrival at random times

    # Entry section
    mutex.acquire()
    read_count += 1
    if read_count == 1:   # First reader locks the resource
        rw_mutex.acquire()
    mutex.release()

    # Critical section (reading)
    print(f"📖 Reader {id} is reading...")
    time.sleep(0.5)

    # Exit section
    mutex.acquire()
    read_count -= 1
    if read_count == 0:   # Last reader releases the resource
        rw_mutex.release()
        print(f"📖 Reader {id} is done reading.")
    mutex.release()

def writer(id):
    global read_count
    time.sleep(random.random())  # Simulate arrival at random times

        # Entry section (exclusive access)
    rw_mutex.acquire()

        # Critical section (writing)
    print(f"✍️ Writer {id} is writing...")
    time.sleep(1)

        # Exit section
    rw_mutex.release()

t1 = threading.Thread(target=reader, args=(1,))
t2 = threading.Thread(target=writer, args=(1,))
t3 = threading.Thread(target=reader, args=(2,))
t4 = threading.Thread(target=reader, args=(3,))
t1.start()
t2.start()
t3.start()
t4.start()
t1.join()
t2.join()
t3.join()
t4.join()