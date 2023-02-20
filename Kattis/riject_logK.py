K = int(input())

M = [[0, 1],
     [1, 1]]

ans = M

def matrix_mul(X,Y):
    return [[sum(a*b for a,b in zip(X_row,Y_col)) for Y_col in zip(*Y)] for X_row in X]

# def matrix_pow2():
#     M = [
#     [ M[0][0]*M[0][0] + M[0][1]*M[1][0], M[0][0]*M[0][1] + M[0][1]*M[1][1] ],
#     [ M[1][0]*M[0][0] + M[

while K > 0:
    if K%2 != 0:
        ans = matrix_mul(ans,M)
        K -= 1
    else:
        ans = matrix_mul(ans,ans)
        K //= 2

ans = matrix_mul(ans, [[1],[0]])

print(ans)
