A,B = [int(x) for x in input()]
M = [[0]*10]*9

def mult_matrix(A,B):
    C = [[0]*10]*9
    for i in range(9):
        for j in range(10):
            C[i][j] += A[

def pow_matrix(A, n):
    if n == 1:
        return A
    if n%2 == 1:
        return mult_matrix(A, pow_matrix(A,n-1))

    C = pow_matrix(A, n//2)
    return mult_matrix(C, C)
