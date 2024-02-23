void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;

    printf("enter size of array:");
    scanf("%d", &n);
    int a[n];

    printf("enter elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Original array is:");
    printArray(a, n);

    printf("All subsets of given array are:");
    printAllSubsets(a, n);

    // check if disjoint set can exist. means 2 sets have same sum
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    if (sum % 2 == 0)
    {
        printf("\nDisjoint set exists!");
    }
    else
    {
        printf("\ndisjoint sets dont exist");
        return 0;
    }

    printf("\nAll partition based disjoint sets are:");
    printpartitiondisjoint(a, n, sum/2);
    printf("\nNo of operation count is %d", opcount);
}