#!/usr/bin/env python3
import sys
import argparse
import pathlib
import time


# === CONFIGURAÇÃO DO DIRETÓRIO DE INSTÂNCIAS ===
BASE_DIR = pathlib.Path(__file__).parent / "instancias-num"


# === ALGORITMOS DE ORDENAÇÃO ===
def selection_sort(seq: list[int]) -> None:
    """Ordena a lista in-place usando Selection Sort."""
    n = len(seq)
    for i in range(n - 1):
        smallest = i
        for j in range(i + 1, n):
            if seq[j] < seq[smallest]:
                smallest = j
        seq[i], seq[smallest] = seq[smallest], seq[i]


def insertion_sort(seq: list[int]) -> None:
    """Ordena a lista in-place usando Insertion Sort."""
    for i in range(1, len(seq)):
        key = seq[i]
        j = i - 1
        while j >= 0 and seq[j] > key:
            seq[j + 1] = seq[j]
            j -= 1
        seq[j + 1] = key


# === FUNÇÕES AUXILIARES ===
def load_numbers(path: pathlib.Path) -> list[int]:
    """Lê um arquivo texto e devolve a lista de inteiros."""
    try:
        text = path.read_text().strip()
        return [int(x) for x in text.split()]
    except FileNotFoundError:
        print(f"[ERRO] Arquivo não encontrado: {path}", file=sys.stderr)
        sys.exit(1)
    except ValueError as e:
        print(f"[ERRO] Formato inválido em {path}: {e}", file=sys.stderr)
        sys.exit(1)


def benchmark(func, data: list[int]) -> float:
    """Retorna o tempo (em segundos) que a função leva para ordenar uma cópia dos dados."""
    copy = data[:]  # mantém os dados originais intactos
    start = time.perf_counter()
    func(copy)
    end = time.perf_counter()
    return end - start


# === CORPO PRINCIPAL ===
def run_all(file_name: str) -> None:
    inst_path = BASE_DIR / file_name
    numbers = load_numbers(inst_path)
    print(f"\n📂 Carregado '{file_name}' ({len(numbers)} elementos)\n")

    results: dict[str, float] = {}
    for name, alg in (("Selection Sort", selection_sort), ("Insertion Sort", insertion_sort)):
        print(f"▶️  Executando {name}...")
        elapsed = benchmark(alg, numbers)
        results[name] = elapsed
        print(f"   ✔️  {name} levou {elapsed:.6f} s\n")

    sel = results["Selection Sort"]
    ins = results["Insertion Sort"]
    diff = abs(sel - ins)

    print("――――――――――――――――――――――――――――――――――――")
    if sel < ins:
        winner = "Selection Sort"
    elif ins < sel:
        winner = "Insertion Sort"
    else:
        winner = "Ambos (empate)"
    print(f"🏆 Vencedor: {winner} (diferença de {diff:.6f} s)")
    print("――――――――――――――――――――――――――――――――――――\n")


def run_single(file_name: str, which: str) -> None:
    inst_path = BASE_DIR / file_name
    numbers = load_numbers(inst_path)
    alg = selection_sort if which == "selection" else insertion_sort
    label = "Selection Sort" if which == "selection" else "Insertion Sort"

    print(f"\n▶️  Rodando apenas {label} em '{file_name}' com {len(numbers)} números...")
    t = benchmark(alg, numbers)
    print(f"   ✔️  Tempo total: {t:.6f} segundos\n")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        prog="compare_sorts",
        description="Compara tempos de Selection Sort e Insertion Sort"
    )
    sub = parser.add_subparsers(dest="command", required=True)

    p_all = sub.add_parser("all", help="Roda ambos os algoritmos e compara")
    p_all.add_argument("file", help="Arquivo de instância (ex: num.1000.1.in)")

    p_one = sub.add_parser("one", help="Roda apenas um dos algoritmos")
    p_one.add_argument("file", help="Arquivo de instância")
    p_one.add_argument(
        "-a", "--algorithm",
        choices=["selection", "insertion"],
        required=True,
        help="Escolha 'selection' ou 'insertion'"
    )
    return parser.parse_args()


def main():
    args = parse_args()
    if args.command == "all":
        run_all(args.file)
    else:
        run_single(args.file, args.algorithm)


if __name__ == "__main__":
    main()
