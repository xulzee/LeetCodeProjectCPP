//
// Created by liuze.xlz on 2019-09-08.
//
#include <utility>

#include "utils.h"

//from是指从哪个桶中倒水，to是指将水倒向哪个桶，water是此次倒水动作所倒的水量。
struct Action {
    int from_;
    int to_;
    int water_;
};

struct BucketState {
    vector<int> max_bucket_nums_;
    vector<int> cur_bucket_nums_;
    Action cur_action_{};
    int target_;

    BucketState(vector<int> cur_bucket_nums, vector<int> max_bucket_nums, int target) {
        cur_bucket_nums_ = std::move(cur_bucket_nums);
        max_bucket_nums_ = std::move(max_bucket_nums);
        target_ = target;
    }

    bool IsBucketEmpty(int from) {
        return cur_bucket_nums_[from] <= 0;
    }

    bool IsBucketFull(int to) {
        return cur_bucket_nums_[to] == max_bucket_nums_[to];
    }

    void SetCurAction(int from, int to, int water) {
        cur_action_.from_ = from;
        cur_action_.to_ = to;
        cur_action_.water_ = water;
    }

    void SetCurBucket(vector<int> &cur_bucket_nums) {
        cur_bucket_nums_ = cur_bucket_nums;
    }

    void GetCurBucket(vector<int> &cur_bucket_nums) {
        cur_bucket_nums = cur_bucket_nums_;
    }

    bool IsFinalState() {
        for (auto &water : cur_bucket_nums_) {
            if (water == target_) {
                return true;
            }
        }
        return false;
    }
};

bool IsCurrentActionValid(BucketState &current, int from, int to) {
    /*不是同一个桶，且from桶中有水，且to桶中不满*/
    return (from != to) && !current.IsBucketEmpty(from) && !current.IsBucketFull(to);
}

bool DumpWater(BucketState &current, int from, int to, BucketState &next, int bucket_size) {
    vector<int> bucket_water(bucket_size, 0);
    current.GetCurBucket(bucket_water);
    int dump_water = current.max_bucket_nums_[to] - bucket_water[to];
    if (bucket_water[from] > dump_water) {
        bucket_water[to] += dump_water;
        bucket_water[from] -= dump_water;
    } else {
        bucket_water[to] += bucket_water[from];
        dump_water = bucket_water[from];
        bucket_water[from] = 0;
    }
    if (dump_water > 0) /*是一个有效的倒水动作?*/
    {
        next.SetCurBucket(bucket_water);
        next.SetCurAction(from, to, dump_water);
    }
    return dump_water > 0;
}


int bfs(vector<int> &max_num, int target) {
    if (max_num[0] + max_num[1] + max_num[2] < target) {
        return -1;
    }

    stack<BucketState *> status_stack;
    stack<pair<vector<int>, int>> status;
    status.push(make_pair({0, 0, 0}, 0))
    for (auto &status : max_num) {

    }

}
