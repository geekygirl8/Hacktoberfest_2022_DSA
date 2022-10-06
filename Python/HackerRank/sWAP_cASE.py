def swap_case(s):
    str=""
    for i in range(len(s)):
        if s[i].isupper() == True:
            str+= s[i].lower()
        else:
            str+= s[i].upper()
    
    return(str)

