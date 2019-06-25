//
// Created by Keren Dong on 2019-06-20.
//

#ifndef WINGCHUN_RUNNER_H
#define WINGCHUN_RUNNER_H

#include <kungfu/practice/apprentice.h>
#include <kungfu/wingchun/strategy/context.h>
#include <kungfu/wingchun/strategy/strategy.h>

namespace kungfu
{
    namespace wingchun
    {
        namespace strategy
        {
            class Runner : public practice::apprentice
            {
            public:
                Runner(bool low_latency, yijinjing::data::locator_ptr locator, const std::string &group, const std::string &name);

                virtual ~Runner() = default;

                void add_strategy(const Strategy_ptr& strategy);

            protected:
                void react(const rx::observable<yijinjing::event_ptr> &events) override ;

                void start() override ;

            private:
                Context_ptr context_;
                std::vector<Strategy_ptr> strategies_;
            };
        }
    }
}

#endif //WINGCHUN_RUNNER_H
