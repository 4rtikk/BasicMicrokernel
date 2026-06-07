#include "task.h"
#include "scheduler.h"
#include "memory.h"
#include "uart.h"

/* Tasks para teste */
void task1()
{
    while (1)
    {
        yield();
    }
}

void task2()
{
    while (1)
    {
        yield();
    }
}

/* Kernel e testes do Heap */
void kernel_main()
{
    /* 1. Inicializa o Heap */
    memory_init();

    uart_print("\n=== Teste do Gerenciador de Memoria ===\n");

    uart_print("Heap total: ");
    uart_print_uint(memory_total());
    uart_print(" bytes\n");

    /* 2. Criação de Tasks (Alocação) */
    xTaskCreate(task1, 2048, 1);
    uart_print("Task 1 criada\n");
    
    xTaskCreate(task2, 2048, 1);
    uart_print("Task 2 criada\n");

    /* Mostra o uso após alocações */
    uart_print("Heap usado: ");
    uart_print_uint(memory_used());
    uart_print(" bytes\n");

    uart_print("Heap livre: ");
    uart_print_uint(memory_free());
    uart_print(" bytes\n");

    /* 3. Remoção da Task 1 */
    xTaskDelete(0);
    uart_print("\nTask 1 removida\n");

    uart_print("Heap usado: ");
    uart_print_uint(memory_used());
    uart_print(" bytes\n");

    uart_print("Heap livre: ");
    uart_print_uint(memory_free());
    uart_print(" bytes\n");

    /* 4. Remoção da Task 2 */
    xTaskDelete(1);
    uart_print("\nTask 2 removida\n");

    uart_print("Heap usado: ");
    uart_print_uint(memory_used());
    uart_print(" bytes\n");

    uart_print("Heap livre: ");
    uart_print_uint(memory_free());
    uart_print(" bytes\n");

    uart_print("=======================================\n");

    scheduler_start();
}