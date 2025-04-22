package javaApp;

// This class represents a task that can be processed by a worker thread
public class Task {
    private final int id;   // Unique ID of the task

    // Constructor to initialize the task with its ID
    public Task(int id) {
        this.id = id;
    }

    // Getter method to retrieve the task ID
    public int getId() {
        return id;
    }

    // Simulates the processing of the task
    // Introduces a delay to mimic computation time
    public void process() throws InterruptedException {
        // Simulate computation delay
        Thread.sleep(500);
    }

    @Override
    public String toString() {
        return "Task - " + id;
    }
}
