A = [7,2,5,8,1,9,3,6]
n= len(A)
def BubbleSort(A):
    flag = True
    while flag:
        flag = False
        for i in range(0, n-1):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]
                flag = True
    return A
BubbleSort(A)
print(A)
