// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    if (n == 0) {
        return -1;
    }

    int left = 1;
    int right = n;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        bool flag = isBadVersion(mid);
        if (flag != true) {
            left = mid + 1;
        } else if (flag == true) {
            right = mid - 1;
        }
    }
    if (left > n || isBadVersion(left) != true) {
        return -1;
    }
    return left;
}