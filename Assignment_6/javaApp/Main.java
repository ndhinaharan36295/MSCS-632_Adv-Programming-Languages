package javaApp;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) {
        final int NUM_WORKERS = 4;  // Number of worker threads
        final int NUM_TASKS = 10;   // Number of tasks to process

        TaskQueue queue = new TaskQueue();  // Shared task queue
        Object resultLock = new Object();   // Lock for synchronizing results writing

        // Load tasks into the shared queue
        for (int i = 1; i <= NUM_TASKS; i++) {
            queue.addTask(new Task(i));
        }

        // Create a fixed thread pool with the specified number of workers
        ExecutorService executor = Executors.newFixedThreadPool(NUM_WORKERS);

        BufferedWriter writer = null;
        try {
            // Open a file writer to write task results
            writer = new BufferedWriter(new FileWriter("results.txt"));
            for (int i = 1; i <= NUM_WORKERS; i++) {
                // Submit worker threads to the executor
                executor.execute(new Worker(i, queue, resultLock, writer));
            }
        } catch (IOException e) {
            // Handling file opening errors
            System.err.println("Failed to open results file: " + e.getMessage());
        }

        // Shutdown the executor and wait for all tasks to complete
        executor.shutdown();
        try {
            // Wait for all tasks to complete
            executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            // Handling interruption during executor shutdown
            System.err.println("Executor interrupted: " + e.getMessage());
        }

        // Close writer only after all threads are done
        if (writer != null) {
            try {
                writer.close();
            } catch (IOException e) {
                // Handle errors during writer closing
                System.err.println("Failed to close writer: " + e.getMessage());
            }
        }

        // Logging the completion of the program
        System.out.println("All tasks processed. Check results.txt.");
    }
}
