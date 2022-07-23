res = []
solved_problems = []

with open('README.md') as f:
    lines = f.readlines()

    for i in lines:
        if(i.count('|') != 5):
            res.append(i)
            continue
        
        info = i.split("`*")
        diff = info[len(info)-1].split('`')[0]
        
        solved_problems.append((int(diff), i))


solved_problems = sorted(solved_problems, key=lambda x: -x[0])

for i in solved_problems:
    res.append(i[1])

text_file = open("formatted.md", "w")
 
for i in res:
    text_file.write(i)
 
text_file.close()

    