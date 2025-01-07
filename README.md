# Control Automático de Servomotores mediante ADC y PWM Para T-Rex de Google

Este proyecto implementa un sistema embebido que controla automáticamente dos servomotores utilizando valores obtenidos desde un ADC (Convertidor Analógico-Digital) para ajustar sus posiciones en función de un umbral predefinido.

## Características

- **Lectura de datos analógicos**: Utiliza un ADC con resolución de 12 bits para capturar valores analógicos.
- **Evaluación de umbrales**: Compara los valores leídos con un umbral (690) para determinar los ángulos de los servomotores.
- **Control de servomotores**: Ajusta las posiciones de los servos mediante señales PWM calculadas.
- **Funcionamiento autónomo**: Opera de forma cíclica y continua sin intervención del usuario.

## Estructura del Proyecto

El programa consta de los siguientes pasos principales:

1. **Inicialización de periféricos**: Configura el ADC y el módulo PWM para operar correctamente.
2. **Lectura de valores del ADC**: Obtiene valores analógicos desde el canal configurado.
3. **Evaluación de umbrales**: Determina los ángulos de los servos en función del valor del ADC.
4. **Generación de PWM**: Convierte los ángulos calculados en pulsos PWM adecuados.
5. **Control de servomotores**: Envía las señales PWM para ajustar las posiciones de los servos.
6. **Repetición**: Introduce un pequeño retraso (10 ms) y repite el proceso.

## Configuración del Código

### Pines
- **Servo 1**: GPIO 14
- **Servo 2**: GPIO 12
- **Entrada ADC**: GPIO 33

### Parámetros de PWM
- **Frecuencia**: 50 Hz
- **Ancho de pulso mínimo**: 500 µs
- **Ancho de pulso máximo**: 2500 µs
- **Rango de ángulos**: 0° a 180°

## Ejecución

1. Conecta los servomotores a los pines especificados.
2. Configura y compila el código en el microcontrolador.
3. Alimenta el sistema.
4. Observa cómo los servos ajustan sus posiciones en función de la entrada analógica.

## Casos de Uso

1. **Inicialización de periféricos**:
   - Configura el ADC y el módulo PWM.
2. **Lectura de valores**:
   - Obtiene un valor analógico del ADC y lo utiliza para el control.
3. **Evaluación de umbrales**:
   - Compara el valor del ADC con un umbral predefinido para calcular los ángulos de los servos.
4. **Control de servomotores**:
   - Ajusta las posiciones de los servos en función de las señales PWM generadas.



