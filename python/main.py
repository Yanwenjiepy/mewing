from queue import Queue


# loadFile 加载源文件内容
def loadFile(file: str, mList: list, fmList: list):
    with open(file, "r") as f:
        for i in f:
            lineLen = len(i)
            gender = i[lineLen-2]
            name = i[:3]

            if gender == "F":
                fmList.append(name)
            elif gender == "M":
                mList.append(name)
            else:
                print("性别标识错误!!!")


def enQueue(queue: Queue, peppleList: list):

    for p in peppleList:
        if queue.full():
            return

        queue.put(p)

    return


if __name__ == '__main__':
    filePath = "people_list"
    mList, fmList = [], []

    loadFile(filePath, mList, fmList)
    mQueueCap = len(mList)
    fmQueueCap = len(fmList)
    maxQeueuCap = mQueueCap
    if fmQueueCap > mQueueCap:
        maxQeueuCap = fmQueueCap

    mQueue = Queue(maxQeueuCap)
    fmQueue = Queue(maxQeueuCap)

    for i in range(0, 2):
        print(f"第{i+1}轮舞曲开始。。。")
        print("男生入场站队。。。")

        enQueue(mQueue, mList)
        print("男生站队完毕。。。")

        print()
        print("女生入场站队。。。")
        enQueue(fmQueue, fmList)
        print("女生站队完毕。。。")

        print()
        print("开始匹配舞伴。。。")

        minQueueSize = fmQueueCap
        if mQueueCap < fmQueueCap:
            minQueueSize = mQueueCap

        for j in range(0, minQueueSize):

            mp = mQueue.get()
            fmp = fmQueue.get()

            print(f"第{j+1}组舞伴匹配结果: 男->{mp} 女->{fmp}")

        print(f"第{i+1}轮舞曲结束。。。")
        print("------------------------------------------------")
        print()
