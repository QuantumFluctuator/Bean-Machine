#include <iostream>
#include <ctime>

using namespace std;

struct BALLINFO {
    int bucketindex;
    char* directions;
};

int main(int argc, const char * argv[]) {
    BALLINFO* DetermineBallBuckets(const int numberOfBalls, const int numberOfLevels);
    int* TallyBalls(const int numberOfBalls, const BALLINFO* balls, const int numberOfBuckets);
    void DisplayBucketContents(const int numberOfBuckets, const int* buckets);
    
    BALLINFO *balls;
    int *buckets, numberOfBalls, numberOfLevels;
    
    srand((int)time(0));
    
    cout << "Enter the number of balls to drop: ";
    cin >> numberOfBalls;
    
    cout << "Enter the number of levels to drop balls through: ";
    cin >> numberOfLevels;
    
    balls = DetermineBallBuckets(numberOfBalls, numberOfLevels);
    buckets = TallyBalls(numberOfBalls, balls, numberOfLevels + 1);
    DisplayBucketContents(numberOfLevels + 1, buckets);
    
    free(balls);
    free(buckets);
    return 0;
}

BALLINFO* DetermineBallBuckets(const int numberOfBalls, const int numberOfLevels) {
    BALLINFO* balls = (BALLINFO*)calloc(sizeof(BALLINFO), numberOfBalls);
    
    for (int i(0); i < numberOfBalls; i++) {
        for (int j(0); j < numberOfLevels; j++) {
            if (rand()%2 == 0) {
                balls[i].bucketindex++;
                //balls[i].directions[j] = 'R';
            } else {
                //balls[i].directions[j] = 'L';
            }
        }
    }
    
    return balls;
}

int* TallyBalls(const int numberOfBalls, const BALLINFO* balls, const int numberOfBuckets) {
    int* buckets = (int*)calloc(sizeof(int), numberOfBuckets);
    
    for (int i(0); i < numberOfBalls; i++) {
        buckets[balls[i].bucketindex]++;
    }
    
    return buckets;
}

void DisplayBucketContents(const int numberOfBuckets, const int* buckets) {
    for (int i(0); i < numberOfBuckets; i++) {
        cout << buckets[i] << endl;
    }
}
