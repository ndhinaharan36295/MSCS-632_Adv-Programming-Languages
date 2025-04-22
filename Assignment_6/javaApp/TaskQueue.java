package javaApp;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

// This class represents a queue of tasks that can be processed by worker threads
public class TaskQueue {
    // Thread-safe Blocking Queue to hold tasks
    private final BlockingQueue<Task> queue = new LinkedBlockingQueue<>();

    // Adds a task to the queue
    public void addTask(Task task) {
        queue.offer(task);
    }

    // Retrieves and removes a task from the queue
    // Returns null if the queue is empty
    public Task getTask() throws InterruptedException {
        return queue.poll();
    }

    // Checks if the queue is empty
    // Returns true if the queue is empty, false otherwise
    public boolean isEmpty() {
        return queue.isEmpty();
    }
}
