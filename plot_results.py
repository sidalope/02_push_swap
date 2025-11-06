#!/usr/bin/env python3
"""
Fully AI written plotter for visualising performance during acceptance tests
Creates a bar chart showing the relationship between list size and number of operations.
"""

import matplotlib.pyplot as plt
import csv
import sys
import os

def read_csv_data(filename):
    """Read CSV data and return sizes and operations lists."""
    if not os.path.exists(filename):
        print(f"Error: File '{filename}' not found.")
        return None, None
    
    try:
        with open(filename, 'r') as file:
            reader = csv.reader(file)
            rows = list(reader)
            
            if len(rows) < 2:
                print(f"Error: CSV file must have at least 2 rows (sizes and operations).")
                return None, None
            
            # Parse sizes (first row)
            sizes = [int(x.strip()) for x in rows[0]]
            
            # Parse operations (second row)
            operations = [int(x.strip()) for x in rows[1]]
            
            if len(sizes) != len(operations):
                print(f"Error: Number of sizes ({len(sizes)}) doesn't match number of operations ({len(operations)}).")
                return None, None
            
            return sizes, operations
    
    except Exception as e:
        print(f"Error reading CSV file: {e}")
        return None, None

def create_bar_chart(sizes, operations, output_file=None, title="Push Swap Performance"):
    """Create and display/save a bar chart."""
    plt.figure(figsize=(12, 8))
    
    # Create bar chart
    bars = plt.bar(range(len(sizes)), operations, alpha=0.7, color='steelblue', edgecolor='black', linewidth=0.5)
    
    # Customize the chart
    plt.xlabel('Test Number (List Size)', fontsize=12)
    plt.ylabel('Number of Operations', fontsize=12)
    plt.title(title, fontsize=14, fontweight='bold')
    plt.grid(axis='y', alpha=0.3)
    
    # Set x-axis labels to show sizes
    plt.xticks(range(len(sizes)), [str(size) for size in sizes], rotation=45 if len(sizes) > 20 else 0)
    
    # Add value labels on top of bars (for smaller datasets)
    if len(sizes) <= 30:
        for i, (bar, ops) in enumerate(zip(bars, operations)):
            plt.text(bar.get_x() + bar.get_width()/2, bar.get_height() + max(operations)*0.01, 
                    str(ops), ha='center', va='bottom', fontsize=8)
    
    # Improve layout
    plt.tight_layout()
    
    # Save or show
    if output_file:
        plt.savefig(output_file, dpi=300, bbox_inches='tight')
        print(f"Chart saved to: {output_file}")
    else:
        plt.show()

def create_scatter_plot(sizes, operations, output_file=None, title="Push Swap Performance"):
    """Create a scatter plot to better show the relationship between size and operations."""
    plt.figure(figsize=(10, 6))
    
    plt.scatter(sizes, operations, alpha=0.6, s=50, color='darkred', edgecolors='black', linewidth=0.5)
    
    plt.xlabel('List Size', fontsize=12)
    plt.ylabel('Number of Operations', fontsize=12)
    plt.title(f"{title} - Size vs Operations", fontsize=14, fontweight='bold')
    plt.grid(True, alpha=0.3)
    
    plt.tight_layout()
    
    if output_file:
        scatter_file = output_file.replace('.png', '_scatter.png')
        plt.savefig(scatter_file, dpi=300, bbox_inches='tight')
        print(f"Scatter plot saved to: {scatter_file}")
    else:
        plt.show()

def main():
    # Default CSV file
    csv_file = "test_push_swap_detailed.csv"
    
    # Check if a different CSV file was provided as argument
    if len(sys.argv) > 1:
        csv_file = sys.argv[1]
    
    print(f"Reading data from: {csv_file}")
    
    # Read the CSV data
    sizes, operations = read_csv_data(csv_file)
    
    if sizes is None or operations is None:
        return 1
    
    print(f"Found {len(sizes)} data points")
    print(f"Size range: {min(sizes)} - {max(sizes)}")
    print(f"Operations range: {min(operations)} - {max(operations)}")
    
    # Generate output filename based on input
    base_name = os.path.splitext(csv_file)[0]
    output_file = f"{base_name}_chart.png"
    
    # Create bar chart
    create_bar_chart(sizes, operations, output_file, f"Push Swap Performance - {os.path.basename(csv_file)}")
    
    # Create scatter plot for better size analysis
    create_scatter_plot(sizes, operations, output_file, f"Push Swap Performance - {os.path.basename(csv_file)}")
    
    return 0

if __name__ == "__main__":
    exit(main())