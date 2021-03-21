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

def solution(program, flag_rules, commands):
    answer = []

    flag_argument_type = ["NULL","NUMBER","STRING"]
    flag_name = []


    # key : flag name, value : flag argument type
    ruleDict = defaultdict(str)


    # Dictionary와 flag_name setting
    for rule in flag_rules :
        split = rule.split()
        ruleDict[split[0]] = split[1]
        flag_name.append(split[0])

    for command in commands :
        split = command.split()

        # flag가 command 안에서 몇 회 등장했는지 확인하는 Dictionary
        flag_count = defaultdict(int)


        # program 이름 일치 확인
        if split[0] != program :
            answer.append(False)
            continue

        # command iterator
        idx = 1

        # 해당 command가 유효한지 기록
        valid = True
        while idx < len(split) :

            # flag가 1회 초과 등장했을 경우 확인
            if split[idx] in flag_name :
                valid = checkFlagCounts(flag_count,split[idx])

            # NULL
            if ruleDict[split[idx]] == flag_argument_type[0] :
                if idx+1 < len(split) and split[idx+1] not in flag_name :
                    valid = False
                idx += 1

            # NUMBER
            elif ruleDict[split[idx]] == flag_argument_type[1] :
                valid = checkNumber(split,idx)
                idx += 2

            # STRING
            elif ruleDict[split[idx]] == flag_argument_type[2] :
                valid = checkString(split,idx)
                idx += 2



            # 존재하지 않는 flag
            else :
                valid = False

            # False이면 더 확인하지 않고 break
            if not valid :
                break


        if valid :
            answer.append(True)
        else :
            answer.append(False)





    return answer

