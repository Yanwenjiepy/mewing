#include <stdio.h>
#include <string.h>

struct peopleNum {
    int mNum;
    int fmNum;
};

struct peopleInfo {
    char* firstChar;
    char* secondChar;
    char* thirdChar;
};

struct peopleNum getPeopleNum();

int initQueue();
int getPeople(char *fileName, struct peopleInfo *mList, struct peopleInfo *fmList);

int put(int queueLen, struct peopleInfo *a, int front, int rear, struct peopleInfo data);
int get(int queueLen, struct peopleInfo *a, int front, int rear);

int getPeople(char *fileName, struct peopleInfo *mList, struct peopleInfo *fmList) {

    FILE *fp;
    char buf[32];

    int mNum = 0;
    int fmNum = 0;

    fp = fopen(fileName, "r");

    //每次读取一行数据，直到读取失败
    while(fgets(buf, sizeof(buf), fp))
    {

        int bufLen = strlen(buf);
        printf("len: %d\n", bufLen);
        printf("%c%c%c", buf[0], buf[1], buf[2]);
        printf("%c%c%c", buf[3], buf[4], buf[5]);
        printf("%c%c%c\n", buf[6], buf[7], buf[8]);

        char name1[4], name2[4], name3[4];
        sprintf(name1, "%c%c%c", buf[0], buf[1], buf[2]);
        sprintf(name2, "%c%c%c", buf[3], buf[4], buf[5]);
        sprintf(name3, "%c%c%c", buf[6], buf[7], buf[8]);

        struct peopleInfo p = {};
        p.firstChar = name1;
        p.secondChar = name2;
        p.thirdChar = name3;

        // 获取性别
        char gender = buf[bufLen - 2];

        // 判断男性还是女性
        switch (gender) {
            case 'M':
                mList[mNum] = p;
                mNum++;
                break;

            case 'F':
                fmList[fmNum] = p;
                fmNum++;
                break;

            default: ;
                break;
        }
    }
    fclose(fp);
    return 0;
};

int initQeue(char *fileName, int mqL, int fmql, struct peopleInfo *mQueue, struct peopleInfo *fmQueueu) {

    return 0;
};

int main() {
    // 获取男女生数量
    char file[14] = "./people_list";
    struct peopleNum res = getPeopleNum(file);

    int mealNum = res.mNum;
    int famealNum = res.fmNum;

    struct peopleInfo mealList[mealNum];
    struct peopleInfo famealList[famealNum];

    getPeople(file, mealList, famealList);

    for (int i = 0; i < mealNum; i++) {
        printf("meal: %s%s%s\n", mealList[i].firstChar, mealList[i].secondChar, mealList[i].thirdChar);
    };

    return 0;

}

// 入队列
int put(int queueLen, struct peopleInfo *a, int front, int rear, struct peopleInfo data){
    //添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
    if ((rear+1)%queueLen==front) {
        printf("空间已满\n");
        return rear;
    }
    a[rear%queueLen]=data;
    rear+=1;
    return rear;
}

// 出队列
int get(int queueLen, struct peopleInfo *a,int front,int rear){
    //如果front==rear，表示队列为空
    if(front==rear%queueLen) {
        printf("队列为空\n");
        return front;
    }

    printf("%s%s%s\n", a[front].firstChar, a[front].secondChar, a[front].thirdChar);
    //front不再直接 +1，而是+1后同max进行比较，如果=max，则直接跳转到 a[0]
    front=(front+1)%queueLen;
    return front;
}

// getPeople 获取源文件中男性和女性数量
struct peopleNum getPeopleNum(char *fileName)
{
    FILE *fp;
    char buf[32];

    int mNum = 0;
    int fmNum = 0;

    struct peopleNum res;

    fp = fopen(fileName, "r");

    //每次读取一行数据，直到读取失败
    while(fgets(buf, sizeof(buf), fp))
    {

        int bufLen = strlen(buf);

        // 获取性别
        char gender = buf[bufLen - 2];

        // 判断男性还是女性
        switch (gender) {
            case 'M':
                mNum++;
                break;

            case 'F':
                fmNum++;
                break;

            default: ;
                break;
        }
    }
    fclose(fp);

    res.mNum = mNum;
    res.fmNum = fmNum;

    return res;
}