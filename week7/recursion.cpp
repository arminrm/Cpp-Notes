//there is a basis and recursive part to function
//Essential: check basis before using the recursive part
//Essential: recursive part "brings" you closer to the basis

int factorial(int n){

    if (n == 1){

        return 1;
    }

    return (n*factorial(n - 1)); //functions are still in suspense
}

//summing array

int sum_array(int *a, int left, int right){

    if (left == right){

        return a[left];
    }
    else{
        return a[left] + sum_array(a, left + 1, right);
    }
}

//printing linked list

void rprint (listNode * p){

    if (p == NULL){

        return;
    }
    rprint(p -> next);
    cout << p -> data;
}

//Quicksort

int SelectAndShuffle (int *A, int left, int right){

    int LastSmall = left;
    int temp;

    for (int i = left + 1; i <= right; i++){

        if (A[i] <= A[left]){

            LastSmall = LastSmall + 1;
            temp = A[i];
            A[i] = A[LastSmall];
            A[Lastsmall] = temp;
        }
    }
    temp = A[left];
    A[left] = A[Lastsmall];
    A[Lastsmall] = temp;
    return Lastsmall;
}

void QuickSort (int *A, int left, int right){

    int PivotIndex;

    PivotIndex = SelectAndShuffle(A, left, right);

    if (PivotIndex > left){
        QuickSort (A, left, PivotIndex -1);
    }

    if (PivotIndex < right){

        QuickSort(A, PivotIndex +1, right);
    }

}

Node* Reverse(Node *p){

    if (p == nullptr){

        return nullptr;
    }

    Node* restofList = p -> next;
    Node* reversedList = Reverse(p -> next);

    if (reversedList != nullptr){

        restofList -> next = p;
    }
    else{

        reversedList = p;
    }

    p -> next = nullptr;
    return (reversedList);
}