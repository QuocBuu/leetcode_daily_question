int elevatorRequests(int n, int* requests, int requestsSize) {
    int ret = requests[0];
    for (int i = 1; i < requestsSize; i++) {
        ret += abs(requests[i] - requests[i-1]);
    }
    return ret;
}