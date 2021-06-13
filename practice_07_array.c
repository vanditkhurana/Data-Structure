#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array *arr){
    printf("\nPrinting Elements....\n");
    printf("|");
    for (int i = 0; i < arr->length; i++)
    {
        printf("| %d |", arr->A[i]);
    }
    printf("|");
    printf("\n");   
}

void Append(struct Array *arr, int val){
    

    if (arr->length < arr->size){
        arr->A[arr->length] = val;
        arr->length++;
        printf("%d Inserted Successfully\n", val);
    }
    else{
        printf("Not Enough Space to insert %d\n", val);
    }
}

void Insert(struct Array *arr, int index, int val){

    if (index >= 0 && index <= arr->length){
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = val;
        arr->length++;
        printf("Element %d Inserted at Index %d Successfully\n", val, index);
        
    }
    else{
        printf("Not able to insert\n");
    }
}

int Delete(struct Array *arr, int index){

    int x = 0;
    if (index >= 0 && index < arr->length){
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
        
    }
    return 0;
}

void swap(int *i, int *j){
    int t;
    t = *i;
    *i = *j;
    *j = t;
}

int LinearSearch(struct Array *arr, int key){
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i]){
            swap(&arr->A[i], &arr->A[i-1]);  // Transpolation
            // return i-1;

            // swap(&arr->A[i], &arr->A[0]); // Move to Head
            // return 0;

            return i;
        }
    }
    return -1;    
}

int BinarySearch(struct Array arr, int key){
    int l, mid, h;
    l = 0;
    h = arr.length;
    while (l <= h)
    {
        mid = (l+h)/2;
        if (key == arr.A[mid]){
            return mid;
        }
        else if (key < arr.A[mid]){
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
    
}

int RBinarySearch(int a[], int l, int h, int key){
    int mid;
    if (l <= h){
        mid = (l + h)/2;
        if (key == a[mid]){
            return mid;
        }
        else if (key < a[mid]){
            return RBinarySearch(a, l, mid-1, key);
        }
        else{
            return RBinarySearch(a, mid+1, h, key);
        }
    }
    return -1;
}

int Get(struct Array arr, int index){
    if (index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int key){
    if (index >= 0 && index < arr->length){
        arr->A[index] = key;
    }
    else{
        printf("Not able to Set...");
    }
}

int Max(struct Array arr){
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
    
}

int Min(struct Array arr){
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;   
}

int Sum(struct Array arr){
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    return sum;
}


int main(){
    
    char choice;
    int n;
    int val, index;
    struct Array arr = {{1,2,3,4,15}, 10, 5};
    do
    {
        printf("\nEnter Choice...\n");
        printf("1. Display\n");
        printf("2. Append\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search\n");
        printf("8. Exit\n");


        printf("Enter Choice : ");
        scanf("%d", &n);

        switch (n)
        {
        
        case 1:
            Display(&arr);
            break;

        case 2:
            printf("\nEnter Value to Append : ");
            scanf("%d",&val);
            Append(&arr, val);
            break;

        case 3:
            printf("\nEnter Index and Value : ");
            scanf("%d %d",&index, &val);
            Insert(&arr, index, val);
            break;

        case 4:
            printf("\nEnter Index to delete : ");
            scanf("%d",&index);
            Delete(&arr, index);
            break;

        case 5:
            printf("\nEnter Value to Search : ");
            scanf("%d",&val);
            printf("%d found at index %d\n", val, LinearSearch(&arr, val));
            break;

        case 6:
            printf("\nEnter Value to Search : ");
            scanf("%d",&val);
            printf("%d found at index %d\n", val, BinarySearch(arr, val));
            break;


        case 8:
            choice = 'n';
            break;
        
        default:
            printf("\nInvalid Choice...\n");
            break;
        }


    } while (choice != 'n');
    
    return 0;
}