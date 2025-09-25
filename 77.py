s=input()
a="QWERTYUIOPASDFGHJKLZXCVBNM"
b="0123456789"
if s[0] not in a: print ('no')
else:
    if s[1] not in b or s[2] not in b or s[3] not in b:print ('no')
    else:
        if s[4] not in a or s[5] not in a:
            print ('no')
        else: print('yes')
