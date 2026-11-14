
def merge(left,right):
    res=[]
    i=0 #left
    j=0 #right

    while i<len(left) and j<len(right):
        if left[i]<=right[j]:
            res.append(left[i])
            i+=1
        else:
            res.append(right[j])
            j+=1
    
    while j<len(right):
        res.append(right[j])
        j+=1
    
    while i<len(left):
        res.append(left[i])
        i+=1

    return res


                

    


def mergeSort(nums):
    if not nums:
            return nums
    if len(nums)==1:
        return nums
    
        i=0
        j=len(nums)//2
        k=len(nums)-1
        left=merge()