#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void dibujar_triangulo_sierpinski(int nivel, int x, int y, int tamaño) {
    if (nivel == 0) {
        // Dibujar un triángulo simple con asteriscos
        for (int i = 0; i < tamaño; i++) {
            for (int j = 0; j < i + 1; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else {
        // Recursión: dividir en triángulos más pequeños
        int nuevo_tamaño = tamaño / 2;
        dibujar_triangulo_sierpinski(nivel - 1, x, y, nuevo_tamaño);
        dibujar_triangulo_sierpinski(nivel - 1, x + nuevo_tamaño, y, nuevo_tamaño);
        dibujar_triangulo_sierpinski(nivel - 1, x + nuevo_tamaño/2, y + nuevo_tamaño, nuevo_tamaño);
    }
}

void mostrar_secuencia_fibonacci(int n) {
    printf("\n=== SECUENCIA DE FIBONACCI ===\n");
    printf("Los primeros %d números de Fibonacci:\n", n);
    
    long long a = 0, b = 1, siguiente;
    
    if (n >= 1) printf("0 ");
    if (n >= 2) printf("1 ");
    
    for (int i = 3; i <= n; i++) {
        siguiente = a + b;
        printf("%lld ", siguiente);
        a = b;
        b = siguiente;
    }
    printf("\n");
    
    // Mostrar la razón áurea aproximada
    if (n > 2) {
        double razon_aurea = (double)b / (double)a;
        printf("Razón áurea aproximada: %.6f\n", razon_aurea);
        printf("Razón áurea real: 1.618034\n");
    }
}

void algoritmo_ordenamiento_burbuja() {
    printf("\n=== ALGORITMO DE ORDENAMIENTO BURBUJA ===\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Algoritmo burbuja con visualización paso a paso
    for (int i = 0; i < n - 1; i++) {
        printf("Pasada %d:\n", i + 1);
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                printf("  Intercambio: %d <-> %d\n", arr[j + 1], arr[j]);
            }
        }
        
        printf("  Estado: ");
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n\n");
    }
    
    printf("Array ordenado final: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mostrar_patron_ascii() {
    printf("\n=== PATRÓN MATEMÁTICO ASCII ===\n");
    printf("Generando un patrón basado en funciones trigonométricas:\n\n");
    
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 60; x++) {
            double valor = sin(x * 0.1) * cos(y * 0.2) * 10;
            if (valor > 5) printf("█");
            else if (valor > 2) printf("▓");
            else if (valor > -2) printf("▒");
            else if (valor > -5) printf("░");
            else printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║        ¡BIENVENIDO A CIENCIAS DE LA COMPUTACIÓN!        ║\n");
    printf("║              Compilado desde Emacs con amor             ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    int opcion;
    
    do {
        printf("\n¿Qué concepto te gustaría explorar?\n");
        printf("1. Secuencia de Fibonacci y Razón Áurea\n");
        printf("2. Algoritmo de Ordenamiento (Burbuja)\n");
        printf("3. Arte ASCII con Matemáticas\n");
        printf("4. Información sobre este programa\n");
        printf("0. Salir\n");
        printf("\nElige una opción (0-4): ");
        
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                mostrar_secuencia_fibonacci(15);
                break;
            case 2:
                algoritmo_ordenamiento_burbuja();
                break;
            case 3:
                mostrar_patron_ascii();
                break;
            case 4:
                printf("\n=== ACERCA DE ESTE PROGRAMA ===\n");
                printf("Este programa demuestra varios conceptos fundamentales:\n");
                printf("• Recursión (Fibonacci)\n");
                printf("• Algoritmos de ordenamiento\n");
                printf("• Matemáticas aplicadas (trigonometría)\n");
                printf("• Programación estructurada\n");
                printf("• Visualización de datos\n\n");
                printf("¡Todo compilado y ejecutado desde Emacs!\n");
                printf("Comando usado: M-x compile -> gcc -o fractales fractales.c\n");
                break;
            case 0:
                printf("\n¡Gracias por explorar ciencias de la computación!\n");
                printf("Recuerda: Emacs es tu mejor amigo para programar 🚀\n");
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
        }
        
        if (opcion != 0) {
            printf("\nPresiona Enter para continuar...");
            getchar(); // Limpiar buffer
            getchar(); // Esperar Enter
        }
        
    } while (opcion != 0);
    
    return 0;
}
