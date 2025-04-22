package javaApp;

import java.io.BufferedWriter;
import java.io.IOException;

// This class represents a Worker class/thread that processes tasks from the TaskQueue
public class Worker implements Runnable {
    private final int id;                   // Unique ID of the worker
    private final TaskQueue queue;          // Shared task queue
    private final Object resultLock;        // Lock for synchronizing results writing
    private final BufferedWriter writer;    // Writer to write task results

    // Constructor to initialize the worker with its ID, task queue, result lock, and writer
    public Worker(int id, TaskQueue queue, Object resultLock, BufferedWriter writer) {
        this.id = id;
        this.queue = queue;
        this.resultLock = resultLock;
        this.writer = writer;
    }

    @Override
    public void run() {
        System.out.println("Worker-" + id + " started.");
        while (true) {
            Task task;
            try {
                // Retrieve a task from the queue
                task = queue.getTask();
                if (task == null) break;  // exit loop if queue is empty

                // Process the task
                task.process();

                // Write the task result to the file with synchronization
                synchronized (resultLock) {
                    writer.write("Worker-" + id + " completed " + task + "\n");
                }
            } catch (InterruptedException e) {
                // Handling interruption during task retrieval
                System.err.println("Worker-" + id + " was interrupted.");
                break;
            } catch (IOException e) {
                // Handling errors during result writing
                System.err.println("Worker-" + id + " failed to write result: " + e.getMessage());
            }
        }
        // Logging the completion of the worker
        System.out.println("Worker-" + id + " completed.");
    }
}
