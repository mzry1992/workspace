#include <stdio.h>
#include <string.h>

#define MAX_INT 0x7fffffff
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n, m, path[1010][1010]��/* ˫������ͼ */
int map[1010]�� /* ��¼��ĵ�ǰ����ֵ */
int processed[1010]; /* ��Ǹõ��Ƿ��ѱ���ȡ */

/* ��ʼ��map,Ϊ�˳�ȡ���ֵ */
void init_single_source(int size)
{
    int i;
    memset(map, 0, sizeof(map));
    map[1] = MAX_INT;
}

int extract_max(int size)
{
    int i, max, max_idx;

    max = 0;
    for (i=1 ; i<=size ; i++)
    {
        if (0 == processed[i] && map[i] > max)
        {
            max = map[i];
            max_idx = i;
        }
    }
    processed[max_idx] = 1;
    return max_idx;
}

int solve(int size)
{
    int i, j, max_idx, min;

    init_single_source(size);
    for (i=1 ; i<=size ; i++)
    {
        max_idx = extract_max(size);
        for (j=1 ; j<=size ; j++)
        {
            if (0 == processed[j] && 0 != path[max_idx][j])
            {
                /* ѡ������·���ϵıߵ���Сֵ */
                min = MIN(map[max_idx], path[max_idx][j]);
                /* ѡȡ�ɵ��ﵱǰ���·���е���С��ֵ�����ֵ */
                if (min > map[j])
                    map[j] = min;
            }
        }
    }

    return map[size];
}

int main(int argc, char *argv[])
{
    int cas, i, j, a, b, w, ret;

    scanf("%d", &cas);
    for (i=1 ; i<=cas ; i++)
    {
        memset(path, 0, sizeof(path));
        memset(processed, 0, sizeof(processed));
        scanf("%d %d", &n, &m);
        for (j=1 ; j<=m ; j++)
        {
            scanf("%d %d %d", &a, &b, &w);
            path[a][b] = path[b][a] = w;
        }

        ret = solve(n);
        printf("Scenario #%d:\n%d\n\n", i, ret);
    }
}
