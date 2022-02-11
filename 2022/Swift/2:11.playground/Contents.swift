import Foundation
import Darwin

//프로그래머스 레벨1 : 신고 결과 받기

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    
    var reportDict: [String: [String]] = [:]
    var answer = [Int](repeating: 0, count: id_list.count)
    var idDict: [String: Int] = [:]
    
    for (index, id) in id_list.enumerated() {
        idDict[id] = index
    }
    
    for rep in report {
        let sep = rep.components(separatedBy: " ")
        let (reporter, reportee) = (sep[0], sep[1])
        
        if reportDict[reportee] != nil {
            if !reportDict[reportee]!.contains(reporter) {
                reportDict[reportee]!.append(reporter)
            }
        }
        else {
            reportDict[reportee] = [reporter]
        }
    }
        
    for (_,value) in reportDict {
        if value.count >= k {
            for reporter in value {
                answer[idDict[reporter]!] += 1
            }
        }
    }
    
    return answer
}



//프로그래머스 숫자 문자열과 영단어
func solution(_ s:String) -> Int {
    let numDict: [String: String] = ["zero": "0", "one": "1", "two": "2", "three": "3", "four": "4", "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"]
    
    var answer = ""
    var str = s
    var tmp = ""
    while !str.isEmpty {
        tmp += String(str.remove(at: str.startIndex))
        if tmp.allSatisfy({ $0.isNumber}) {
            answer += tmp
            tmp = ""
        }
        else if numDict[tmp] != nil {
            answer += numDict[tmp]!
            tmp = ""
        }
    }
    
    return Int(answer) ?? 0
}


// 프로그래머스 없는 숫자 더하기

func solution(_ numbers:[Int]) -> Int {
    return 45 - numbers.reduce(0,+)
}
