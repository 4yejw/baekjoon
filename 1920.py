N = int(input())
N_list = list(map(int,input().split()))
N_list.sort()
M = int(input())
M_list = list(map(int,input().split()))

def BinarySearch(List,First,Last,Key):
    if First>Last:
        return 0
    else:
        mid = (First + Last) //2
        if List[mid]==Key:
            return 1
        elif List[mid] > Key:
            return BinarySearch(List,First,mid-1,Key)
        elif List[mid]<Key:
            return BinarySearch(List,mid+1,Last,Key)

for k in range(M):
    print(BinarySearch(N_list,0,len(N_list)-1,M_list[k]))
