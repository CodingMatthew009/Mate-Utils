


// Class for executing function after n time (may be relocated)
struct TimedTask
{
    template<typename time_type = std::chrono::milliseconds> 
    TimedTask(const char* name, time_type time, std::function<void()> function)
    {
        task_thread = std::thread([time, this, function] {
            if (time != std::chrono::milliseconds(0))
            {
                Timer task_timer = Timer();

                while ((task_timer.get_time<std::chrono::milliseconds>() < time.count()) || !started)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }
            else
            {
                while (!started)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }

            function();
        });
    }

    inline void start_task()
    {
        started = true;
    }

    inline void join_task()
    {
        task_thread.join();
    }

    private:            
        bool started = false;

        std::thread task_thread;

};