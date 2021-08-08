from itertools import permutations
AllGames = [[1,2],[2,3],[3,4],[1,3],[2,4],[1,4]]
Points = [0 for i in range(5)]
Team = int(input())
Temp = []
AlrGames = int(input())
C = 0
Outcomes = ["W","L","T"]*(6-AlrGames)
PossibleWinComps = list(set(permutations(Outcomes, 6-AlrGames)))
for i in range(AlrGames):
    A,B,SA,SB = map(int,input().split())
    if A>B:
        A,B = B,A
        SA,SB = SB,SA
    if SA > SB:
        Points[A]+=3
    elif SA < SB:
        Points[B]+=3
    else:
        Points[A]+=1
        Points[B]+=1
    AllGames.remove([A,B])

TempPoints = Points[:]

for i in range(len(PossibleWinComps)):
    TempAllGames = list(AllGames)
    for j in range(len(AllGames)):
        Temp = TempAllGames.pop(0)
        if PossibleWinComps[i][j] == 'W':
            Points[Temp[0]]+=3
        elif PossibleWinComps[i][j] == 'T':
            Points[Temp[1]]+=1
            Points[Temp[0]]+=1
        else:
            Points[Temp[1]]+=3
    if max(Points) == Points[Team] and Points.count(max(Points)) == 1:
        C+=1
    Points = TempPoints[:]
print(C)