import threading
import time

# Parking lot with max 2 cars allowed
parking_lot = threading.Semaphore(2)

def car(car_id):
    print(f"Car {car_id} is waiting to park...")
    parking_lot.acquire()   # wait (P)
    print(f"Car {car_id} has parked.")

    time.sleep(2)  # car stays for 2s

    print(f"Car {car_id} is leaving.")
    parking_lot.release()   # signal (V)

def main():
    threads = []
    for i in range(1, 5):   # 4 cars
        t = threading.Thread(target=car, args=(i,))
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

if __name__ == "__main__":
    main()
