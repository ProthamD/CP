# import threading

# cv = threading.Condition()
# data_ready = False

# def consumer():
#     global data_ready
#     with cv:  # acquire lock
#         while not data_ready:  # check condition
#             cv.wait()  # release lock and wait
#         print("Data is ready! Consuming it...")

# def producer():
#     global data_ready
#     with cv:
#         data_ready = True
#         cv.notify()  # wake up one waiting thread
#         print("Produced data!")

# # Run threads
# t1 = threading.Thread(target=consumer)
# t2 = threading.Thread(target=producer)

# t1.start()
# t2.start()
# t1.join()
# t2.join()


import threading

from lightgbm import cv

empty = threading.Semaphore(1)  # buffer empty
full = threading.Semaphore(0)  # buffer full
data_ready = False

def consumer():
    global data_ready
    full.acquire() # wait for data
    print("Data is ready! Consuming it...")
def producer():
    global data_ready
    empty.acquire() # wait for space
    print("Produced data!")
    full.release() # signal that buffer is full

t1 = threading.Thread(target=consumer)
t2 = threading.Thread(target=producer)

t1.start()
t2.start()
t1.join()
t2.join()

