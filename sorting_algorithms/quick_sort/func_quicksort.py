# note : not in place, but more readable imo 
def partition_sort(xs): 
    if not xs: return xs

    gt, eq, lt = [], [], []

    for x in xs:
        if x < xs[0]:  
            lt.append(x)
        elif x > xs[0]:
            gt.append(x)
        else: 
            eq.append(x)
    return partition_sort(lt) + eq + partition_sort(gt)

a = [0, 5, 2, 4, 6, 1, 3]
print(partition_sort(a))