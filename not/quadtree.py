def reverse(str,i):
    if len(str)==1:
        return str, index+1
    while(i<len(str)):
        if (str[i] is 'b') or (str[i] is 'w'):
            upperleft=reverse(str, i)
            upperright=reverse(str, i)
            lowerleft=reverse(str, i)
            lowerright=(str, i)
            

reverse(str,0)
