import pandas as pd
import matplotlib.pyplot as plt

# Tasas de aprendizaje y números de épocas
learning_rates = ["0.000100", "0.000010", "0.000001"]
epoch_counts = [100, 500, 1000]

# Ruta base donde se encuentran los archivos CSV
base_path = "/home/camposjulca/Repos_cristhiamdaniel/ProgramacionAvanzada/cmake-build-debug/"

# Leer los datos de puntos x, y solo una vez
sample_file = f"{base_path}lr_{learning_rates[0]}_epochs_{epoch_counts[0]}.csv"
sample_data = pd.read_csv(sample_file)

# Crear figuras y ejes para los subplots
fig, axs = plt.subplots(1, len(learning_rates), figsize=(15, 5), sharey=True, dpi=300)

# Graficar los puntos x, y una sola vez por subplot con opacidad reducida
for ax in axs:
    ax.scatter(sample_data['x'], sample_data['y'], label='Datos', alpha=0.5)  # Reducir opacidad

# Graficar las líneas de predicción para cada tasa de aprendizaje
for i, lr in enumerate(learning_rates):
    for epochs in epoch_counts:
        filename = f"{base_path}lr_{lr}_epochs_{epochs}.csv"
        pred_data = pd.read_csv(filename)
        axs[i].plot(pred_data['x'], pred_data['y_pred'], label=f'Predicción (epochs={epochs})')

    axs[i].set_title(f"Tasa de Aprendizaje = {lr}")
    axs[i].set_xlabel("x")
    axs[i].legend()

axs[0].set_ylabel("y")

# Ajustar diseño
plt.tight_layout()

# Guardar la imagen en alta calidad
plt.savefig(
    "/home/camposjulca/Repos_cristhiamdaniel/ProgramacionAvanzada/cmake-build-debug/learning_rates_comparison.png")

# Mostrar el gráfico
plt.show()
