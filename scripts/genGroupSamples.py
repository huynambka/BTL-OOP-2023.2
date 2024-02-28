import numpy as np
import argparse
from scipy import stats


def generateSamples(num_samples, total_value, lower_bound, upper_bound):

    # Số lượng mẫu, tổng giá trị của các mẫu, cận dưới và cận trên của các giá trị mẫu

    # Tính giá trị trung bình và độ lệch chuẩn
    mean = total_value / num_samples
    # Giả sử rằng 99.7% dữ liệu nằm trong khoảng 3 độ lệch chuẩn từ giá trị trung bình
    std_dev = (mean - lower_bound) / 3

    # Tạo ra các mẫu ngẫu nhiên tuân theo phân phối chuẩn
    samples = np.random.normal(mean, std_dev, num_samples)

    # Chuẩn hóa các mẫu sao cho tổng của chúng bằng với total_value
    samples = samples * total_value / np.sum(samples)

    # Đảm bảo rằng tất cả các mẫu đều nằm trong khoảng từ lower_bound đến upper_bound
    samples = np.clip(samples, lower_bound, upper_bound)
    samples = np.round(samples, 0)

    # Kiểm tra xem liệu các mẫu này có tuân theo phân phối chuẩn không bằng cách sử dụng kiểm định Shapiro-Wilk
    stat, p = stats.shapiro(samples)
    alpha = 0.05

    values = samples.astype(int)
    max_idx = values.argmax()

    # Hoán đổi phần tử lớn nhất với phần tử đầu tiên
    values[0], values[max_idx] = values[max_idx], values[0]
    print(values)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate group samples')
    parser.add_argument('--num-samples', type=int,
                        default=6, help='Number of samples')
    parser.add_argument('--total-value', type=int,
                        default=30000, help='Total value of samples')
    parser.add_argument('--lower-bound', type=int,
                        default=1000, help='Lower bound of sample values')
    parser.add_argument('--upper-bound', type=int,
                        default=10000, help="Upper bound of sample values")
    args = parser.parse_args()
    generateSamples(args.num_samples, args.total_value,
                    args.lower_bound, args.upper_bound)
