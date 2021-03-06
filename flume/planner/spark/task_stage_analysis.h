/***************************************************************************
 *
 * Copyright (c) 2016 Baidu, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 **************************************************************************/
// Author: Pan Yuchang(BDG)<panyuchang@baidu.com>
//         Wang Cong<wangcong09@baidu.com>
// Description:

#ifndef FLUME_PLANNER_SPARK_TASK_STAGE_ANALYSIS_H_
#define FLUME_PLANNER_SPARK_TASK_STAGE_ANALYSIS_H_

#include <set>
#include <vector>

#include "flume/planner/common/task_flow_analysis.h"
#include "flume/planner/plan.h"

namespace baidu {
namespace flume {
namespace planner {
namespace spark {

class TaskStageAnalysis : public Pass {
public:
    RELY_PASS(BuildRddsPass);

    class BuildRddsPass : public Pass {
    public:
        RELY_PASS(TaskFlowAnalysis);

    private:
        class Impl;

        virtual bool Run(Plan* plan);
    };

private:
    virtual bool Run(Plan* plan) {
        return false;
    }
};

}  // namespace spark
}  // namespace planner
}  // namespace flume
}  // namespace baidu

#endif // FLUME_PLANNER_SPARK_TASK_STAGE_ANALYSIS_H_

