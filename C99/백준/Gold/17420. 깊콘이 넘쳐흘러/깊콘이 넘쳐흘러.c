#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} pair;

int compare(const void *a, const void *b) {
    pair *pairA = (pair *)a;
    pair *pairB = (pair *)b;
    if (pairA->first == pairB->first) {
        return pairA->second - pairB->second;
    }
    return pairA->first - pairB->first;
}

int main() {
    int n;
    long long result = 0;
    pair gift[100000];

    scanf("%d", &n);

    // 남은 기한
    for (int i = 0; i < n; i++) {
        scanf("%d", &gift[i].second);
    }

    // 사용 계획
    for (int i = 0; i < n; i++) {
        scanf("%d", &gift[i].first);
    }

    int extension;
    for (int i = 0; i < n; i++) {
        if (gift[i].second < gift[i].first) {
            extension = ((gift[i].first - gift[i].second + 29) / 30);
            gift[i].second += 30 * extension; // 일단 이만큼 연장은 무조건 필요함.
            result += extension;
        }
    }

    // first : use plan
    // second : valid_period
    // 이때 valid_period는 위에서 연장하여 use plan보다 크도록 보장된 상태.

    // 그러나 이 친구는 가장 적게 기한이 남은 것부터 사용해야 하므로, 기한에 따른 사용 순서가 생각되어야 함.
    // 사용계획, 남은 기한 순으로 정렬.
    qsort(gift, n, sizeof(pair), compare);

    // 사용 계획에 딱 맞추어 사용하긴 할건데 기한이 제일 적어야만 사용이 가능함.
    // 각 기프티콘을 plan별로 모아 생각하면,
    // 두번째 plan의 기프티콘은 첫번째 plan에 사용되어야 하는 기프티콘 중에 가장 만료일이 늦는 것보다 더 늦어야 함.
    // 그래야 첫번째 plan을 모두 마치고 두번째 plan의 기프티콘을 사용할 수 있음.

    // 만약 이전 plan의 기프티콘 중에 만료날짜가 다음 plan보다 큰게 있다면, 그리고 그 만료일이 다음 plan의 다음 기프티콘들보다도 더 많이 남았다면,
    // 가장 먼저 사용되는 기프티콘이 가장 만료날짜가 이른 것임을 보장하기 위해, 뒤에 기프티콘은 더 많이 추가연장을 해야할 것임.

    int maxDate_in_before_plan = 0;

    for (int i = 0; i < n; i++) {
        int group_plan = gift[i].first;

        // i번째 plan(group_plan)과 같은 예정을 가진 날짜를 모두 그룹 지음.
        int group_end = i + 1;
        while (group_end < n) {
            if (group_plan == gift[group_end].first)
                group_end++;
            else
                break;
        }

        int max_in_group = maxDate_in_before_plan;
        for (int j = i; j < group_end; j++) {
            int valid_period_inGroup = gift[j].second;
            if (valid_period_inGroup < maxDate_in_before_plan) { // 이전 plan의 최대 만료일자보다 작으면 연장해야 함.
                extension = (maxDate_in_before_plan - valid_period_inGroup + 29) / 30;
                result += extension;
                valid_period_inGroup += extension * 30;
            }

            // 현재 그룹의 최댓값을 기록. (다음 plan group이 보게.)
            if (valid_period_inGroup > max_in_group)
                max_in_group = valid_period_inGroup;
        }

        maxDate_in_before_plan = max_in_group;

        i = group_end - 1;
    }

    printf("%lld\n", result);
    return 0;
}
