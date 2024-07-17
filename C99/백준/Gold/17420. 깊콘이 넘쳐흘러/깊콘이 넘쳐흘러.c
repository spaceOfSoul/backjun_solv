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

    for (int i = 0; i < n; i++) {
        scanf("%d", &gift[i].second);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &gift[i].first);
    }

    int extension;
    for (int i = 0; i < n; i++) {
        if (gift[i].second < gift[i].first) {
            extension = ((gift[i].first - gift[i].second + 29) / 30);
            gift[i].second += 30 * extension;
            result += extension;
        }
    }

    qsort(gift, n, sizeof(pair), compare);

    int maxDate_in_before_plan = 0;

    for (int i = 0; i < n; i++) {
        int group_plan = gift[i].first;
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
            if (valid_period_inGroup < maxDate_in_before_plan) {
                extension = (maxDate_in_before_plan - valid_period_inGroup + 29) / 30;
                result += extension;
                valid_period_inGroup += extension * 30;
            }

            if (valid_period_inGroup > max_in_group)
                max_in_group = valid_period_inGroup;
        }

        maxDate_in_before_plan = max_in_group;
        i = group_end - 1;
    }

    printf("%lld\n", result);
    return 0;
}
