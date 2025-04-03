#Jordan McCool
#Lab 08
#"complete prologue comments"?
    #if this isnt a complete prologue, then I dont understand it

#im already lost
    #just gonna start by writing notes
#Chapter 9 slide 40 'explains' this but it doesn't make any sense
    #wasnt at lecture due to funeral
        #so I didnt hear him explaint his
#on slide 43, there is an algorithm that seems like it would work?
    #but im still stuck, bc the slide 40 makes ZERO sense without having it explained

#Warshalls algorithm?

#in lab
    #understanding it a bit more.
    #make them a true / false array
    #do either algo 1 or algo 2
    #M^2 is done by multiplication. will probably have to make them true false
    #make a printer function

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
                       
def main(): #little m is the base, big M is the current
    m, n = gather()
    M = m
    if n == 1:
        #print function, ended up making main not the actual main, see printer
        return M
    for i in range(1, n):
        temp = i + 1
        forgot = calc(m, temp) #find the matrix for each power
        M = comp(M, forgot) #overwrites M successively
    return M

def calc(m, c):
    M = m
    for count in range(0, c): #is just repeating the same M^2. Find out why
        M = tryagain(M, m) #this took forever
    return M

def tryagain(m, n): #Multiplies two matrices
    M = []
    t = len(m)
    for i in range(0, t):
        row = []
        for j in range(0, len(m[i])):
            c = False
            for k in range(0, t):
                 c = c or (n[i][k] and m[k][j])
            row.append(c)
        M.append(row)
    return M

def comp(M, N): #M is the current matrix, N is the base to the current power (iteration)
    C = []
    n = len(M)
    for i in range(0, len(M)): #creates another empty matrix, just for help with errors i hope
        temp = []
        for s in range(0, len(M[i])):
            temp.append(False)
        C.append(temp)
    for i in range(0, n):
        for s in range(0, n):
            if M[i][s] or N[i][s]:
                C[i][s] = True
    return C
    
    

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

printer(main())

    

