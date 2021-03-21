from _collections import defaultdict




def solution(program, flag_rules, commands):
    answer = []

    flag_argument_type = ["NULL", "NUMBER", "STRING"]
    flag_name = []

    # key : flag name, value : flag argument type
    ruleDict = defaultdict(str)

    # Dictionary와 flag_name setting
    for rule in flag_rules:
        split = rule.split()
        ruleDict[split[0]] = split[1]
        flag_name.append(split[0])

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
        while idx < len(split) - 1:

            # flag가 1회 초과 등장했을 경우 확인
            if split[idx] in flag_name:
                flag_count[split[idx]] += 1
                if flag_count[split[idx]] > 1:
                    valid = False
                    break

            # NULL
            if ruleDict[split[idx]] == flag_argument_type[0]:
                if split[idx + 1] not in flag_name:
                    valid = False
                    break
                idx += 1

            # NUMBER
            elif ruleDict[split[idx]] == flag_argument_type[1]:
                if not split[idx + 1].isdigit():
                    valid = False
                    break
                idx += 2

            # STRING
            elif ruleDict[split[idx]] == flag_argument_type[2]:
                if not split[idx + 1].isalpha():
                    valid = False
                    break
                idx += 2



            # 존재하지 않는 flag
            else:
                valid = False

        # len == 2 일 때 예외처리
        if len(split) == 2 and ruleDict[split[idx]] != flag_argument_type[0]:
            valid = False

        if valid:
            answer.append(True)
        else:
            answer.append(False)

    return answer



print(solution("line",["-s STRING", "-n NUMBER", "-e NULL"],["line -n 100 -s hi a", "lien -s Bye"]))