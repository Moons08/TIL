import tensorflow as tf
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import sys

# app.flags를 사용해 스크립트에서 받을 옵션과 기본값 설정
tf.app.flags.DEFINE_string("output_graph",
                           "./workspace/flowers_graph.pb",
                           "학습된 신경망이 저장된 위치")
tf.app.flags.DEFINE_string("output_labels",
                           "./workspace/flowers_labels.txt",
                           "학습할 레이블 데이터 파일")
tf.app.flags.DEFINE_boolean("show_image",
                            True,
                            "이미지 추론 후 이미지를 보여줍니다.")

FLAGS =  tf.app.flags.FLAGS

def main(_):
    # 예측에 이용할 label값 로드
    labels = [line.rstrip() for line in tf.gfile.GFile(FLAGS.output_labels)]

    # 학습 결과 로드
    with tf.gfile.FastGFile(FLAGS.output_graph, 'rb') as fp:
        graph_def = tf.GraphDef()
        graph_def.ParseFromString(fp.read())
        tf.import_graph_def(graph_def, name='')

    # 예측에 사용할 텐서 지정
    with tf.Session() as sess:
        logits = sess.graph.get_tensor_by_name('final_result:0') # 최종 출력층 불러오기
        # 예측할 데이터 로드
        image = tf.gfile.FastGFile(sys.argv[1], 'rb').read()
        prediction = sess.run(logits, {'DecodeJpeg/contents:0':image})

    print('===== 예측 결과 =====')
    for  i in range(len(labels)):
        name = labels[i]
        score = prediction[0][i]
        print('%s (%.2f%%)' % (name, score * 100))

    if FLAGS.show_image:
        img = mpimg.imread(sys.argv[1])
        plt.imshow(img)
        plt.show()

if __name__ == "__main__":
    tf.app.run()
