/* Sorting */

void merge(char state[],int size, char arr[], int l, int m, int r, int dir, int tiefe)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
            int b,c;
            int t = 1;
            if(tiefe < t) t = tiefe;
            state[L[i]] = -1;
            if(dir == 1) b = min(state,size,-10000,10000, t);
            else b = max(state,size,-10000,10000, t);
            state[L[i]] = 0;
            state[R[j]] = -1;
            if(dir == 1) c = min(state,size,-10000,10000, t);
            else c = max(state,size,-10000,10000, t);
            state[R[j]] = 0;
        if ((dir == -1 && b <= c) || (dir == 1 && b >= c)) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(char state[],int size,char arr[], int l, int r, int dir,int tiefe)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(state,size,arr, l, m, dir,tiefe);
        mergeSort(state,size,arr, m + 1, r, dir, tiefe);

        merge(state,size,arr, l, m, r, dir, tiefe);
    }
}
