
#include <pthread.h>

#include <iostream>

pthread_mutex_t mtx;
pthread_cond_t condP;
pthread_cond_t condC;
int buf = 0;

void* producer(void* pArgStruct) {
    for (int i = 1; i < 3; i++) {
        pthread_mutex_lock(&mtx);
        std::cout << "Produser: went into critical section buf=" << buf << "\n";
        while (buf != 0) {
            std::cout << "Produser: start wait\n";
            pthread_cond_wait(&condP, &mtx);
        }

        buf = i;
        std::cout << "Produser: set buf to " << buf << "\n";

        pthread_cond_signal(&condC);
        std::cout << "Produser: going out from critical section\n";
        pthread_mutex_unlock(&mtx);
    }
}

void* consumer(void* pArgStruct) {
    for (int i = 1; i < 3; i++) {
        pthread_mutex_lock(&mtx);
        std::cout << "Consumer: went into critical section buf=" << buf << "\n";
        while (buf == 0) {
            std::cout << "Consumer: start wait\n";
            pthread_cond_wait(&condC, &mtx);
        }

        buf = 0;
        std::cout << "Consumer: cleaned buf to " << buf << "\n";

        pthread_cond_signal(&condP);
        std::cout << "Consumer: going out from critical section\n";
        pthread_mutex_unlock(&mtx);
    }
}

int main() {
    pthread_t proT;
    pthread_t conT;
    pthread_mutex_init(&mtx, NULL);
    pthread_cond_init(&condP, NULL);
    pthread_cond_init(&condP, NULL);
    pthread_create(&conT, 0, consumer, 0);
    pthread_create(&proT, 0, producer, 0);
    std::cout << "Before joins\n";
    pthread_join(proT, 0);  // ?
    std::cout << "After join proT\n";
    pthread_join(conT, 0);  // ?
    std::cout << "After join conT\n";
    pthread_cond_destroy(&condP);
    pthread_cond_destroy(&condC);
    pthread_mutex_destroy(&mtx);

    return 0;
}