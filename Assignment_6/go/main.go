package main

import (
	"fmt"
	"log"
	"math/rand"
	"os"
	"sync"
	"time"
)

// Task struct representing a unit of work to be processed by a worker
type Task struct {
	ID int
}

// Simulate processing work of a time
func (t Task) Process() {
	time.Sleep(time.Millisecond * 500) // simulate computation time
}

// Worker function that processes tasks from the task channel

// id: worker ID
// tasks: channel to receive tasks
// wg: WaitGroup to signal task completion
// file: file to write results
// mutex: mutex to ensure safe concurrent writes to the file
func worker(id int, tasks <-chan Task, wg *sync.WaitGroup, file *os.File, mutex *sync.Mutex) {
	defer wg.Done()
	fmt.Printf("Worker-%d started.\n", id)

    // Process tasks from the channel
	for task := range tasks {
		task.Process()
		output := fmt.Sprintf("Worker-%d completed Task-%d\n", id, task.ID)

		// Write result to file with mutex protection
		mutex.Lock()
		_, err := file.WriteString(output)
		if err != nil {
			log.Printf("Worker-%d error writing file: %v\n", id, err)
		}
		mutex.Unlock()
	}

	fmt.Printf("Worker-%d completed.\n", id)
}

func main() {
	const numWorkers = 4 // Number of worker goroutines
	const numTasks = 10  // Number of tasks to process

	// Create result file to write the result
	file, err := os.Create("results.txt")
	if err != nil {
		log.Fatalf("Failed to create result file: %v", err)
	}
	defer file.Close() // Ensure file is closed when main exits

	// Channel to hold tasks and sync tools
	tasks := make(chan Task, numTasks)
	var wg sync.WaitGroup
	var mutex sync.Mutex

	// Launch worker goroutines
	for i := 1; i <= numWorkers; i++ {
		wg.Add(1)
		go worker(i, tasks, &wg, file, &mutex)
	}

	// Send tasks to queue
	for i := 1; i <= numTasks; i++ {
		tasks <- Task{ID: i}
	}
	close(tasks) // Close the channel to signal no more tasks

    // Wait for all workers to complete
	wg.Wait()
	fmt.Println("All tasks processed. Check results.txt.")
}
