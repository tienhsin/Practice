from urllib.parse import urlparse

def balance(lines):

    res=[]
    d={}

    for line in lines:
        type = getType(line)
        print(type)

        if type=="API":
            amount=getAmount(line)
            mID=getmID(line)
            dID=getdID(line)
            feetoDest=getDsetFee(line)

            feetoStripe=amount*0.029+30
            amount-=feetoStripe

            if feetoDest!=None and dID!=None:
                amount-=feetoDest
                if dID in d:
                    d[dID]+=feetoDest
                else:
                    d[dID]=feetoDest

            if mID in d:
                d[mID]+=amount
            else:
                d[mID]=amount


        elif type=="BAL":
            ID=getID(line)

            if ID in d:
                res.append(round(d[ID]))
            else:
                res.append(0)
    print(res)
    return res


def getType(line):
    return line.split()[0][:-1]

def getAmount(line):
    try:
        return int(line.split()[1].split("&")[0].split("=")[1])
    except:
        return None

def getmID(line):
    try:
        return line.split()[1].split("&")[1].split("=")[1]
    except:
        return None

def getdID(line):
    try:
        return line.split()[1].split('&')[2].split('=')[1]
    except:
        return None

def getDsetFee(line):
    try:
        return int(line.split()[1].split('&')[3].split('=')[1])
    except:
        return None

def getID(line):
    try:
        return line.split()[1].split('=')[1]
    except:
        return None

#balance(["API: amount=2000&merchant=10101010", "BAL: merchant=10101010"])
balance(["API: amount=1000&merchant=123456789&destination[account]=111111&destination[amount]=877", "API: amount=800&merchant=123456789&destination[account]=112211&destination[amount]=622", "BAL: merchant=123456789", "BAL: merchant=112211"])
#balance(["API: amount=1000&merchant=123456789&destination[account]=111111&destination[amount]=", "API: amount=800&merchant=123456789&destination[account]=112211&destination[amount]=622", "BAL: merchant=123456789", "BAL: merchant=112211"])
