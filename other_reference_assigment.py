#Jordan McCool
#Lab 09
#use warshalls algorithm

def gather(): #going to make this based off an input
    n = int(input('Enter size of square matrix (ie 4):\n'))
    out = []
    for i in range(0, n):
        temp = row(i, n)
        out.append(temp)
    return converter(out), n #converts to a bool array, returns it and size

def row(i, n):
    user = input(f'Enter comma seperated list for row {i+1}: \n')
    user = user.split(',')
    for index in range(0, len(user)):
        user[index] = user[index].strip()
        try:
            user[index] = int(user[index])
        except:
            raise ValueError('Invalid entry?')
    if len(user) == n:
        return user
    else:
        print(f'the length of that row was detected as {len(user)} instead of {n}. Retry')
        return row #recursive to handle error

def converter(out): #converts to bool
    for i in range(0, len(out)):
        for s in range(0, len(out[i])):
            if out[i][s] == 0:
                out[i][s] = False
            else:
                out[i][s] = True
    return out

def printer(M): #deconverts and  prints
    print('\n')
    for i in range(0, len(M)): #converts, could have also printed but wanted some order incase errors
        for s in range(0, len(M[i])):
            if M[i][s]:
                M[i][s] = 1
            else:
                M[i][s] = 0
    for i in range(0, len(M)):
        for s in range(0, len(M[i])):
            print(M[i][s], end=' ')
            if s == (len(M[i])-1):
                print('\n')
                
##
    #The three functions above were copied from last weeks lab.
    #They get the input matrix, and printer prints it
    #new stuff below
##

def main():
    M, n = gather()
    printer(warshall(M, n))

def warshall(M, n): #warshalls algorithm, mostly from slide 43 chapter 9
    m = M
    for k in range(0, n):
        for i in range(0, n):
            for j in range(0, n):
                m[i][j] = m[i][j] or (m[i][k] and m[k][j])
    return m
main()
