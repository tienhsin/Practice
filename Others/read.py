
fname=input()

m={}
with open(fname, 'r') as fin:
    for line in fin:

        if len(line.split())==0:
            continue

        ip=line.split()[0];

        if ip in m:
            m[ip]=m[ip]+1;
        else:
            m[ip]=1;

fout=open("records_"+fname, 'w')
for key, value in m.items():
    fout.write(str(key) + " "+ str(value )+ '\n')
