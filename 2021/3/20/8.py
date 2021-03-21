from _collections import defaultdict


# NUMBER 조건
def checkNumber(command,idx) :
    if idx + 1 >= len(command) or not command[idx + 1].isdigit():
        return False
    return True

# String 조건
def checkString(command,idx) :
    if idx + 1 >= len(command) or not command[idx + 1].isalpha():
        return False
    return True

# Flag 1회 이하 조건
def checkFlagCounts(countDict,flag) :
    countDict[flag] += 1
    if countDict[flag] > 1:
        return False
    return True

# NUMBERS 조건
def checkNumbers(command,flag_names,idx) :
    if not checkNumber(command,idx) :
        return [False,idx]
    idx += 1
    while idx < len(command) and command[idx] not in flag_names:
        if not command[idx].isdigit():
            return [False,idx]
        idx += 1
    return [True,idx]

# STRINGS 조건
def checkStrings(command,flag_names,idx) :
    if not checkString(command,idx) :
        return [False,idx]

    idx += 1

    while idx < len(command) and command[idx] not in flag_names:
        if not command[idx].isalpha():
            return [False,idx]
        idx += 1
    return [True,idx]



def solution(program, flag_rules, commands):
    answer = []

    flag_argument_type = ["NULL", "NUMBER", "STRING","NUMBERS","STRINGS"]
    flag_name = []

    # key : flag name, value : flag argument type
    ruleDict = defaultdict(str)

    # key : alias name, value : alias의 원래 이름
    aliasDict = defaultdict(str)

    # Dictionary와 flag_name setting
    for rule in flag_rules:
        split = rule.split()
        if split[1] == "ALIAS" :
            aliasDict[split[0]] = split[2]
        else :
            ruleDict[split[0]] = split[1]
        flag_name.append(split[0])

    # alias의 argument type 지정
    for key in aliasDict :
        ruleDict[key] = ruleDict[aliasDict[key]]



    for command in commands:
        split = command.split()

        # flag가 command 안에서 몇 회 등장했는지 확인하는 Dictionary
        flag_count = defaultdict(int)

        if split[0] != program:
            answer.append(False)
            continue

        # command iterator
        idx = 1
        # 해당 command가 유효한지 기록
        valid = True
        while idx < len(split):

            # alias와 원래 이름이 동시에 등장했는지 확인
            if split[idx] in aliasDict :
                if aliasDict[split[idx]] in command :
                    valid = False
                    break
            # flag가 1회 초과 등장했을 경우 확인
            if split[idx] in flag_name:
                valid = checkFlagCounts(flag_count, split[idx])
                if not valid:
                    break

            # NULL
            if ruleDict[split[idx]] == flag_argument_type[0]:
                if idx + 1 < len(split) and split[idx + 1] not in flag_name:
                    valid = False
                    break
                idx += 1

            # NUMBER
            elif ruleDict[split[idx]] == flag_argument_type[1]:
                valid = checkNumber(split, idx)
                idx += 2

            # STRING
            elif ruleDict[split[idx]] == flag_argument_type[2]:
                valid = checkString(split, idx)
                idx += 2

            # NUMBERS
            elif ruleDict[split[idx]] == flag_argument_type[3]:
                res = checkNumbers(split,flag_name,idx)
                valid, idx = res[0], res[1]

            # STRINGS
            elif ruleDict[split[idx]] == flag_argument_type[4]:
                res = checkStrings(split,flag_name,idx)
                valid,idx = res[0],res[1]




            # 존재하지 않는 flag
            else:
                valid = False
                break

            # False이면 더 확인하지 않고 break
            if not valid :
                break




        if valid:
            answer.append(True)
        else:
            answer.append(False)

    return answer