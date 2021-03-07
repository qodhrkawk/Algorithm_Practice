
import heapq


#
# def putLower(n,lowers,highers,length) :
#     heapq.heappush(lowers, -n)
#
#     global median
#
#     if len(lowers) - len(highers) > 0:
#         low_high = -heapq.heappop(lowers)
#         if low_high > median :
#             heapq.heappush(highers, median)
#             median = low_high
#         else :
#             heapq.heappush(highers, low_high)
#
#
#
# def putHigher(n,lowers,highers,length) :
#     heapq.heappush(highers,n)
#     global median
#
#     if len(highers)-len(lowers) > 0 :
#         if length%2 != 0 :
#             high_low = heapq.heappop(highers)
#             if high_low > median :
#                 heapq.heappush(lowers, -median)
#                 median = high_low
#
#             else :
#                 heapq.heappush(lowers, -high_low)
#
#
#




def solution() :
    lowers = []
    highers = []

    median = 0
    n = int(input())

    for i in range(n) :
        new = int(input())

        if i == 0 :
            median = new
        else :
            if median > new :
                heapq.heappush(lowers, -new)


                if len(lowers) - len(highers) > 0:
                    low_high = -heapq.heappop(lowers)
                    if low_high > median:
                        heapq.heappush(highers, median)
                        median = low_high
                    else:
                        heapq.heappush(highers, low_high)

            else :
                heapq.heappush(highers, new)

                if len(highers) - len(lowers) > 0:
                    if (i+1) % 2 != 0:
                        high_low = heapq.heappop(highers)
                        if high_low > median:
                            heapq.heappush(lowers, -median)
                            median = high_low

                        else:
                            heapq.heappush(lowers, -high_low)

        # print(lowers)
        # print(highers)
        print(median)




solution()